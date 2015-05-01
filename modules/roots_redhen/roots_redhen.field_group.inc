<?php
/**
 * @file
 * roots_redhen.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function roots_redhen_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_backup_emergency_contact|redhen_contact|adult|form';
  $field_group->group_name = 'group_backup_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'adult';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_emergency_contact';
  $field_group->data = array(
    'label' => 'Back-up',
    'weight' => '8',
    'children' => array(
      0 => 'field_contact_2_name',
      1 => 'field_contact_2_phone_h',
      2 => 'field_contact_2_phone_w',
      3 => 'field_contact_2_phone_c',
      4 => 'field_contact_2_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-backup-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_backup_emergency_contact|redhen_contact|adult|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_backup_emergency_contact|redhen_contact|kid|form';
  $field_group->group_name = 'group_backup_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'kid';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_emergency_contact';
  $field_group->data = array(
    'label' => 'Back-up',
    'weight' => '20',
    'children' => array(
      0 => 'field_contact_2_name',
      1 => 'field_contact_2_phone_h',
      2 => 'field_contact_2_phone_w',
      3 => 'field_contact_2_phone_c',
      4 => 'field_contact_2_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-backup-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_backup_emergency_contact|redhen_contact|kid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency_contact|redhen_contact|adult|form';
  $field_group->group_name = 'group_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'adult';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Emergency Contact Information',
    'weight' => '8',
    'children' => array(
      0 => 'group_primary_emergency_contact',
      1 => 'group_backup_emergency_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_emergency_contact|redhen_contact|adult|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_emergency_contact|redhen_contact|kid|form';
  $field_group->group_name = 'group_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'kid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Emergency Contact Information',
    'weight' => '8',
    'children' => array(
      0 => 'group_primary_emergency_contact',
      1 => 'group_backup_emergency_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_emergency_contact|redhen_contact|kid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_insurance|redhen_contact|adult|form';
  $field_group->group_name = 'group_health_insurance';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'adult';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Insurance Info',
    'weight' => '7',
    'children' => array(
      0 => 'field_have_health_insurance',
      1 => 'field_insurance_company',
      2 => 'field_insurance_id',
      3 => 'field_insurance_group',
      4 => 'field_primary_physician',
      5 => 'field_physicians_phone',
      6 => 'field_name_insured_relatiionship',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-health-insurance field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_insurance|redhen_contact|adult|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_health_insurance|redhen_contact|kid|form';
  $field_group->group_name = 'group_health_insurance';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'kid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Insurance Info',
    'weight' => '7',
    'children' => array(
      0 => 'field_have_health_insurance',
      1 => 'field_insurance_company',
      2 => 'field_insurance_id',
      3 => 'field_insurance_group',
      4 => 'field_primary_physician',
      5 => 'field_physicians_phone',
      6 => 'field_name_insured_relatiionship',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-health-insurance field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_health_insurance|redhen_contact|kid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_med_info|redhen_contact|adult|form';
  $field_group->group_name = 'group_med_info';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'adult';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Medical Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_allergies_y_n',
      1 => 'field_allergies_list',
      2 => 'field_dietary_concerns',
      3 => 'field_under_medical_care',
      4 => 'field_medical_history',
      5 => 'field_past_operations_injury',
      6 => 'field_physical_restrictions',
      7 => 'field_behavioral_concerns',
      8 => 'field_tetanus_shot',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-med-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_med_info|redhen_contact|adult|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_med_info|redhen_contact|kid|form';
  $field_group->group_name = 'group_med_info';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'kid';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Medical Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_allergies_y_n',
      1 => 'field_allergies_list',
      2 => 'field_dietary_concerns',
      3 => 'field_under_medical_care',
      4 => 'field_medical_history',
      5 => 'field_past_operations_injury',
      6 => 'field_behavioral_concerns',
      7 => 'field_physical_restrictions',
      8 => 'field_tetanus_shot',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-med-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_med_info|redhen_contact|kid|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary_emergency_contact|redhen_contact|adult|form';
  $field_group->group_name = 'group_primary_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'adult';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_emergency_contact';
  $field_group->data = array(
    'label' => 'Primary',
    'weight' => '7',
    'children' => array(
      0 => 'field_contact_1_name',
      1 => 'field_contact_1_relationship',
      2 => 'field_contact_1_phone_h',
      3 => 'field_contact_1_phone_c',
      4 => 'field_contact_1_phone_w',
      5 => 'field_contact_1_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-primary-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_primary_emergency_contact|redhen_contact|adult|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary_emergency_contact|redhen_contact|kid|form';
  $field_group->group_name = 'group_primary_emergency_contact';
  $field_group->entity_type = 'redhen_contact';
  $field_group->bundle = 'kid';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_emergency_contact';
  $field_group->data = array(
    'label' => 'Primary',
    'weight' => '19',
    'children' => array(
      0 => 'field_contact_1_name',
      1 => 'field_contact_1_relationship',
      2 => 'field_contact_1_phone_h',
      3 => 'field_contact_1_phone_w',
      4 => 'field_contact_1_phone_c',
      5 => 'field_contact_1_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-primary-emergency-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_primary_emergency_contact|redhen_contact|kid|form'] = $field_group;

  return $export;
}
