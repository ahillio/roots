<?php
/**
 * Implements hook_rules_condition_info()
 * *** Important ***
 * Currently these conditions are NOT used because using "Process a change to the checkout page"
 *  causes order status to be wrong and messes up checkout process
 * 
 * Rules that use the conditions that check for an audience term must also
 *  check to see if the Order->order_id is NOT empty.
 *  The event "Process a change to the checkout page" gets call before
 *  the order is actually created.
 *
 */
function roots_reg_rules_condition_info() {
  return array(
    'root_reg_rule_condition_order_has_term_youth' => array(
      'label' => t('Check if order has Youth term'),
      'parameter' => array(
        'order' => array('label' => t('Order'), 'type' => 'commerce_order'),
      ),
      'group' => t('Roots Reg'),
    ),
    'root_reg_rule_condition_order_has_term_adult' => array(
      'label' => t('Check if order has Adult term'),
      'parameter' => array(
        'order' => array('label' => t('Order'), 'type' => 'commerce_order'),
      ),
      'group' => t('Roots Reg'),
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function roots_reg_rules_action_info(){
  $actions = array();
  $actions['root_reg_get_recurring_line_items'] = array(
    'label' => t('Roots - Get all the line items containing recurring products from an order'),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
    ),
    'provides' => array(
      'commerce_line_items' => array(
        'label' => t('Line items with recurring products'),
        'type' => 'list<commerce_line_item>',
      ),
    ),
    'group' => t('Roots Reg'),
    'callbacks' => array(
      'execute' => 'roots_reg_rules_get_recurring_line_items',
    ),
  );

  return $actions;
}

/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function root_reg_rule_condition_order_has_term_youth($order) {
  return _roots_reg_rule_condition_order_has_term($order, 'Youth');
}
/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function root_reg_rule_condition_order_has_term_adult($order) {
  return _roots_reg_rule_condition_order_has_term($order, 'Adult');
}

/**
 * Action callback to get line items that should have recurring.
 *
 * Calls commerce_recurring_order_load_recurring_line_items and then
 * removes items where the field field_program_pay_option is not set to deposit-remainder.
 *
 * @param $order
 *
 * @return array
 */
function roots_reg_rules_get_recurring_line_items($order) {
  module_load_include('inc', 'commerce_recurring', 'commerce_recurring.rules');
  $order_line_items = commerce_recurring_order_load_recurring_line_items($order);
  if (isset($order_line_items[$order->order_id])) {
    $line_items = $order_line_items[$order->order_id];
    foreach (array_keys($line_items) as $line_item_id) {
      $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_items[$line_item_id]);
      if ($line_item_wrapper->field_program_pay_option->value() != 'deposit-remainder') {
        unset($line_items[$line_item_id]);
      }
    }
    return array('commerce_line_items' => $line_items);
  }
  return array();
}
