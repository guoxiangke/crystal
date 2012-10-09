<?php

/**
 * @file Includes any rules integration provided by the module.
 */
 /**
 * implementation of hook_rules_condition_info()
 */
function crystal_bar_rules_condition_info() {
  return array(
    'crystal_bar_condition_has_the_best_answer' => array(
      'label' => t('If there is an old best answer for the question already.'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The new answer node.')),
      ),
      'module' => 'crystal_bar',
      'group' => t('Customs'),
    ),
  );
}
/**
 * Condition crystal_bar_condition_has_the_best_answer
 */
function crystal_bar_condition_has_the_best_answer($new_answer) {
	
	$question_nid = $new_answer->field_answer['und']['0']['target_id'];
	$question = node_load($question_nid);
	$answers_array = $question->field_answers['und'];
	$flag_name = 'accepted';// oh..oh,the name must match system flag setting in /admin/structure/flags
	if (!($flag = flag_get_flag($flag_name))) {
	    // Flag does not exist.
	    return FALSE;
	}
	foreach ($answers_array as $key => $value) {
		$nid = $value['target_id'];
		// flag_flag->is_flagged($content_id, $uid = NULL, $sid = NULL)
		if($flag->is_flagged($nid) && $nid!=$new_answer->nid){
			return TRUE;
		}
	}
	return FALSE;
}

 /**
 * implementation of hook_rules_condition_info()
 */
function crystal_bar_rules_action_info() {
  return array(
    'crystal_bar_action_unflag_the_old_answer' => array(
      'label' => t('Unflag the old answer from given new answer,if has.'),
      'arguments' => array(
        'new_answer' => array('type' => 'node', 'label' => t('The new answer someone gives.')),
      ),
      'module' => 'crystal_bar',
      'group' => t('Customs'),
    ),
  );
}
/**
 * Condition packages_condition_packagetype
 */
function crystal_bar_action_unflag_the_old_answer($new_answer) {
	 //Provide the the old answer as parameter to unflag?
	 //do something, no return.

	$question_nid = $new_answer->field_answer['und']['0']['target_id'];
	$question = node_load($question_nid);
	$answers_array = $question->field_answers['und'];
	$flag_name = 'accepted';// here also,the name must match system flag setting in /admin/structure/flags
	if (!($flag = flag_get_flag($flag_name))) {
	    // Flag does not exist.
	    return;
	}
	foreach ($answers_array as $key => $value) {
		$nid = $value['target_id'];
		if($flag->is_flagged($nid) && $nid!=$new_answer->nid){
			flag('unflag',$flag_name,$nid);
			return;
		}
	}
	return;
}