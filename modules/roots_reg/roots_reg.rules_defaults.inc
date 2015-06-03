<?php
/**
 * @file
 * roots_reg.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function roots_reg_default_rules_configuration() {
  $items = array();
  $items['commerce_recurring_roots_recurring_entity_order_is_complete2'] = entity_import('rules_config', '{ "commerce_recurring_roots_recurring_entity_order_is_complete2" : {
      "LABEL" : "Roots recurring entity when order is completed",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce recurring", "Roots Reg" ],
      "REQUIRES" : [ "roots_reg", "commerce_recurring", "commerce_payment" ],
      "ON" : { "commerce_payment_order_paid_in_full" : [] },
      "DO" : [
        { "root_reg_get_recurring_line_items" : {
            "USING" : { "commerce_order" : [ "commerce_order" ] },
            "PROVIDE" : { "commerce_line_items" : { "commerce_line_items" : "Line items with recurring products" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-line-items" ] },
            "ITEM" : { "current_line_item" : "Current line item" },
            "DO" : [
              { "commerce_recurring_generate_recurring_product" : {
                  "commerce_order" : [ "commerce-order" ],
                  "commerce_line_item" : [ "current-line-item" ],
                  "fixed_price" : [ "current-line-item:commerce-unit-price" ],
                  "quantity" : [ "current-line-item:quantity" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_disable_child_info_pane'] = entity_import('rules_config', '{ "rules_disable_child_info_pane" : {
      "LABEL" : "disable child info pane",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "registration" ],
      "REQUIRES" : [ "rules", "roots_reg", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_page" : [] },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "site:current-cart-order:order-id" ] } },
        { "NOT root_reg_rule_condition_order_has_term_youth" : { "order" : [ "site:current-cart-order" ] } }
      ],
      "DO" : [
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "roots_reg_children_info_pane",
            "page_id" : "\\u003Csame\\u003E",
            "enabled" : 0
          }
        },
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "roots_reg_signup_info_pane",
            "page_id" : "\\u003Csame\\u003E",
            "enabled" : 0
          }
        }
      ]
    }
  }');
  $items['rules_disable_personal_info_pane'] = entity_import('rules_config', '{ "rules_disable_personal_info_pane" : {
      "LABEL" : "disable personal info pane",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Checkout", "registration" ],
      "REQUIRES" : [ "rules", "roots_reg", "commerce_rules_extra" ],
      "ON" : { "commerce_rules_extra_process_checkout_page" : [] },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "site:current-cart-order:order-id" ] } },
        { "NOT root_reg_rule_condition_order_has_term_adult" : { "order" : [ "site:current-cart-order" ] } }
      ],
      "DO" : [
        { "commerce_rules_extra_change_pane" : {
            "pane_id" : "roots_reg_personal_pane",
            "page_id" : "\\u003Csame\\u003E",
            "enabled" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
