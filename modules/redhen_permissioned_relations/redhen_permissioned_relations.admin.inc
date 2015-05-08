<?php

/**
 * @file
 * Manages webform bsd administration UI
 */

/**
 * Callback function to edit sitewide configuration options
 */
function redhen_permissioned_relations_config($form, &$form_state) {

	$form = array();

	$form['temp'] = array(
		'#type' => 'markup',
		'#markup' => '<p>Placeholder text for form</p>',
	);

	return system_settings_form($form);
}

function redhen_permissioned_relations_config_validate($form, &$form_state) {
	$values = $form_state['values'];
}

