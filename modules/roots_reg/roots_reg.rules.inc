<?php
/**
 * Implements hook_rules_condition_info().
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


