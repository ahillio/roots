<?php
/**
 * @file
 * roots_redhen.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function roots_redhen_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_redhen_contact_type().
 */
function roots_redhen_default_redhen_contact_type() {
  $items = array();
  $items['adult'] = entity_import('redhen_contact_type', '{
    "name" : "adult",
    "label" : "Adult",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  $items['kid'] = entity_import('redhen_contact_type', '{
    "name" : "kid",
    "label" : "Kid",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}
