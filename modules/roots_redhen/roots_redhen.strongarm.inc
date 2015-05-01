<?php
/**
 * @file
 * roots_redhen.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function roots_redhen_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'redhen_contact_connect_users';
  $strongarm->value = 1;
  $export['redhen_contact_connect_users'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'redhen_contact_mirror_email';
  $strongarm->value = 1;
  $export['redhen_contact_mirror_email'] = $strongarm;

  return $export;
}
