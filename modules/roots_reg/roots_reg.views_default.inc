<?php
/**
 * @file
 * roots_reg.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function roots_reg_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'parents_child_relation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'relation';
  $view->human_name = 'Parents Child Relation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'full_name' => 'full_name',
    'megarow_links' => 'megarow_links',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'full_name' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'megarow_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'No child relations checkout text';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'You must a child info to continue.';
  /* Relationship: Relation: Relation: Child (relation → redhen_contact) */
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['id'] = 'relation_base_child_minor_redhen_contact';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['field'] = 'relation_base_child_minor_redhen_contact';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['required'] = TRUE;
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['r_index'] = '0';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact']['entity_deduplication_right'] = 0;
  /* Relationship: Relation: Relation: Child (relation → redhen_contact) */
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['id'] = 'relation_base_child_minor_redhen_contact_1';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['table'] = 'relation';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['field'] = 'relation_base_child_minor_redhen_contact';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['label'] = 'Child - Parent';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['required'] = TRUE;
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['r_index'] = '1';
  $handler->display->display_options['relationships']['relation_base_child_minor_redhen_contact_1']['entity_deduplication_right'] = 0;
  /* Relationship: User: Contact User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'redhen_contact_user';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'relation_base_child_minor_redhen_contact_1';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Contact: Full name */
  $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['table'] = 'views_entity_redhen_contact';
  $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
  $handler->display->display_options['fields']['full_name']['relationship'] = 'relation_base_child_minor_redhen_contact';
  $handler->display->display_options['fields']['full_name']['link_to_entity'] = 0;
  /* Field: Contact: Contact ID */
  $handler->display->display_options['fields']['contact_id']['id'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['table'] = 'redhen_contact';
  $handler->display->display_options['fields']['contact_id']['field'] = 'contact_id';
  $handler->display->display_options['fields']['contact_id']['relationship'] = 'relation_base_child_minor_redhen_contact';
  $handler->display->display_options['fields']['contact_id']['label'] = 'Edit Contact';
  $handler->display->display_options['fields']['contact_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['text'] = 'Edit Contact';
  $handler->display->display_options['fields']['contact_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['contact_id']['alter']['path'] = 'checkout/!1/roots_reg_children_info?contact_id=[contact_id]';
  $handler->display->display_options['fields']['contact_id']['separator'] = '';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Relation: Relation type */
  $handler->display->display_options['filters']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['table'] = 'relation';
  $handler->display->display_options['filters']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['value'] = array(
    'child_minor' => 'child_minor',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $export['parents_child_relation'] = $view;

  return $export;
}
