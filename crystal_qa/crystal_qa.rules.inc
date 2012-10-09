<?php

/**
 * @file Includes any rules integration provided by the module.
 */

 /**
 * implementation of hook_rules_condition_info()
 * Add a new reference field value to the question when a new answer was created for it. 
 */
function crystal_qa_rules_action_info() {
	return array(
    'crystal_qa_action_new_answer' => array(
      'label' => t('Add the answer to the question\'s Entity Reference field when a new answer was created.'),
      'arguments' => array(
        'answer' => array('type' => 'node', 'label' => t('The answer someone gives.')),
      ),
      'module' => 'crystal_qa',
      'group' => t('Customs'),
    ),
  );
}
/**
 *  Add a new reference field value to the question when a new answer was created for it. 
 */
function crystal_qa_action_new_answer($answer) {
	$question_nid = $answer->field_answer['und']['0']['target_id'];
	$question = node_load($question_nid);
	$question->field_answers['und'][]=array('target_id'=>$answer->nid);
	node_save($question);
}