<?php



/**
 * Checkout form for roots_reg_personal_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_personal_pane_checkout_form($form, $form_state, $checkout_pane, $order) {


  global $user;
  $redhen_contact = redhen_contact_load_by_user($user);
  if (!$redhen_contact) {
    $redhen_contact = redhen_contact_create(array('type' => 'adult'));
    $redhen_contact->setEmail($user->mail);
    $redhen_contact->save();
  }
  _roots_reg_add_redhen_contact_form($redhen_contact, $pane_form, $form_state);
  unset($pane_form['actions']);
  // redhen_contact_contact_form_submit
  return $pane_form;
}

/**
 * Adds Redhen contact form to $pane_form
 *
 * @param $redhen_contact
 * @param $pane_form
 * @param $form_state
 */
function _roots_reg_add_redhen_contact_form($redhen_contact, &$pane_form, $form_state) {
  $pane_form['redhen_contact'] = array(
    '#type' => 'value',
    '#value' => $redhen_contact,
  );
  module_load_include('inc', 'redhen_contact', 'includes/redhen_contact.forms');
  // Add the field widgets for the profile.
  $pane_form = redhen_contact_contact_form($pane_form, $form_state, $redhen_contact);

}

/**
 * Validate callback for roots_reg_personal_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_personal_pane_checkout_form_validate($form, &$form_state, $checkout_pane, $order) {
  return _roots_contact_form_validate($form, $form_state);
}

/**
 * Submit for roots_reg_personal_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_personal_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  _roots_reg_contact_form_submit($form, $form_state);
}

/**
 * Settings for roots_reg_children_info_pane
 *
 * @see roots_reg_commerce_checkout_pane_info().
 */
function roots_reg_children_info_pane_checkout_form($form, $form_state, $checkout_pane, $order) {
  global $user;

  $redhen_contact = redhen_contact_load_by_user($user);
  if (!$redhen_contact) {
    _roots_reg_no_contact_error($user);

  }
  $contact_id = _root_reg_get_qs_contact_id();
  $query_param = drupal_get_query_parameters();
  if ($contact_id) {
    // Show contact edit
    $child_contact = redhen_contact_load($contact_id);
    // Call custom access callback function to determine if this contact is editable.
    if (redhen_permissioned_relations_access('update', $child_contact)) {
      _roots_reg_add_redhen_contact_form($child_contact, $form, $form_state);
      $form['order'] = array(
        '#type' => 'value',
        '#value' => $order,
      );
      $form['actions']['submit']['#submit'] = array(
        '_roots_reg_children_info_pane_contact_submit',
      );
      $form['actions']['submit']['#validate'] = array(
        '_roots_contact_form_validate',
      );

    }
  }
  elseif (!empty($query_param['child_contact_add'])) {
    // Show contact add form
    $child_contact = redhen_contact_create(array('type' => 'kid'));
    _roots_reg_add_redhen_contact_form($child_contact, $form, $form_state);
    // Get actual relationship field from Redhen Relation entity so that changes automatically update.
    $field_instance = field_info_instance('relation', 'field_parentchild_relationship', 'child_minor');
    $field = field_info_field('field_parentchild_relationship');
    $form['relationship'] = array(
      '#type' => 'select',
      '#title' => $field_instance['label'],
      '#options' => $field['settings']['allowed_values'],
      '#weight' => -100,
    );
    $form['order'] = array(
      '#type' => 'value',
      '#value' => $order,
    );
    $form['actions']['submit']['#submit'] = array(
      '_roots_reg_children_info_pane_contact_submit',
      '_roots_reg_children_info_pane_add_relationship',
    );
    $form['actions']['submit']['#validate'] = array(
      '_roots_contact_form_validate',
    );
  }
  else {
    // Show list of child contact by Views
    $view_output = views_embed_view('parents_child_relation', 'default', $order->order_id);
    $form['markup'] = array(
      '#type' => 'markup',
      '#markup' => $view_output,
    );

    $form['add_link'] = array(
      '#type' => 'link',
      '#title' => t('Add new child contact'),
      '#href' => 'checkout/' . $order->order_id . '/roots_reg_children_info' ,
      '#options' => array('query' => array('child_contact_add' => TRUE)),
    );
  }
  return $form;
}
