<?php
/**
 * Settings for roots_reg_children_info_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_signup_info_pane_checkout_form($form, $form_state, $checkout_pane, $order) {

  $youth_line_items = _roots_reg_get_line_items_on_order($order, 'Youth');
  $form['line_item_registrations'] = array(
    '#tree' => TRUE,
  );
  global $user;
  $redhen_contact = redhen_contact_load_by_user($user);
  $child_contacts = _roots_reg_get_all_children_for_contact($redhen_contact);
  // Make list of full names
  $child_names = array();
  foreach ($child_contacts as $child_contact) {
    $contact_wrapper = entity_metadata_wrapper('redhen_contact', $child_contact);
    $child_names[$child_contact->contact_id] = $contact_wrapper->full_name->value();
  }
  foreach ($youth_line_items as $item_id => $line_item_wrapper) {
    $payment_option = $line_item_wrapper->field_program_pay_option->label();
    $form['line_item_registrations'][$item_id] = array(
      '#type' => 'fieldset',
      '#title' => $line_item_wrapper->commerce_product->label(),
      '#description' => t('Payment option') . ': ' . $payment_option,
    );
    $item_registrations = _root_reg_get_registrations_for_line_item($item_id);
    for ($q = 1; $q <= $line_item_wrapper->quantity->value(); $q++) {
      $contact_element = array(
        '#type' => 'select',
        '#title' => t('Registrant #' . $q),
        '#description' => t('@todo explain registration'),
        '#options' => $child_names,
      );
      if (!empty($item_registrations)) {
        $registration_node = array_shift($item_registrations);
        $contact_element['#default_value'] = $registration_node->field_registrant->raw();
      }
      $form['line_item_registrations'][$item_id][] = $contact_element;
    }
  }

  return $form;
}
function _root_reg_get_registrations_for_line_item($line_item_id) {
  $node_wrappers = array();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'program_registration')
    ->fieldCondition('field_line_item', 'target_id', $line_item_id);
  $results = $query->execute();
  if ($results['node']) {
    // Found nodes
    foreach ($results['node'] as $node_info) {
      $node_wrappers[] = entity_metadata_wrapper('node', $node_info->nid);
    }
  }
  return $node_wrappers;
}

/**
 * Validate for roots_reg_signup_info_pane
 *
 *  Validation call back to make sure that all line item ids they submitted are still in their order.
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_signup_info_pane_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  $youth_line_items = _roots_reg_get_line_items_on_order($order, 'Youth');
  $current_line_item_ids = array_keys($youth_line_items);
  $line_item_registrations = $form_state['values']['roots_reg_signup_info_pane']['line_item_registrations'];
  $submitted_line_item_ids = array_keys($line_item_registrations);
  if ($submitted_line_item_ids == $current_line_item_ids) {
    return TRUE;
  }
  form_error($form, t('Your cart contents have changed. Please submit again'));
  return FALSE;
}
/**
 * Submit for roots_reg_signup_info_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_signup_info_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  $line_item_registrations = $form_state['values']['roots_reg_signup_info_pane']['line_item_registrations'];

  foreach ($line_item_registrations as $line_item_id => $contact_ids) {
    // First delete existing nodes
    if ($existing_registrations = _root_reg_get_registrations_for_line_item($line_item_id)) {
      /* @var EntityDrupalWrapper $registration */
      foreach ($existing_registrations as $registration) {
        $registration->delete();
      }
    }

    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item_id);
    $product_id = $line_item_wrapper->commerce_product->getIdentifier();
    foreach ($contact_ids as $contact_id) {
      _roots_reg_create_registration_node($product_id, $contact_id, $line_item_id);
    }
    /**
     * @TODO
     * 6. (optionally) on order delete - delete any nodes that reference order and have status = 0.
     */
  }

}


