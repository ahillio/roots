<?php
/**
 * Implements hook_rules_condition_info().
 */
function roots_reg_rules_condition_info() {
  return array(
    'root_reg_rule_condition_order_has_term_youth' => array(
      'label' => t('Check if order has a term'),
      'parameter' => array(
        'order' => array('label' => t('Order'), 'type' => 'commerce_order'),
      ),
      'group' => t('Roots Reg'),
    ),
    'root_reg_rule_condition_order_has_term_adult' => array(
      'label' => t('Check if order has a term'),
      'parameter' => array(
        'order' => array('label' => t('Order'), 'type' => 'commerce_order'),
      ),
      'group' => t('Roots Reg'),
    ),
  );
}

/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function root_reg_rule_condition_order_has_term_youth($order) {
  _root_reg_rule_condition_order_has_term($order, 'Youth');
}
/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function root_reg_rule_condition_order_has_term_adult($order) {
  _root_reg_rule_condition_order_has_term($order, 'Adult');
}
/**
 * Rules condition: checks to see if the given order is in a cart status.
 */
function _root_reg_rule_condition_order_has_term($order,$term_name) {
  $line_items = _roots_reg_get_line_items_on_order($order, $term_name);
  return !empty($line_items);
}

