<?php
/**
 * @file
 * roots_commerce_entities.features.inc
 */

/**
 * Implements hook_commerce_line_item_default_types().
 */
function roots_commerce_entities_commerce_line_item_default_types() {
  $items = array(
    'long_term_program' => array(
      'name' => 'Long Term Program',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
    'regular_program' => array(
      'name' => 'Regular Program',
      'description' => 'A customizable product line item type.',
      'product' => TRUE,
      'add_form_submit_value' => 'Add product',
      'base' => 'commerce_product_line_item',
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_product_default_types().
 */
function roots_commerce_entities_commerce_product_default_types() {
  $items = array(
    'program' => array(
      'type' => 'program',
      'name' => 'Program',
      'description' => 'Events, Courses, Programs',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function roots_commerce_entities_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function roots_commerce_entities_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function roots_commerce_entities_node_info() {
  $items = array(
    'long_term_program' => array(
      'name' => t('Long Term Program'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'program' => array(
      'name' => t('Program'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
