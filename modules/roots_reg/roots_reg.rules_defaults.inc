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
  return $items;
}
