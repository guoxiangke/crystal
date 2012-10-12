<?php
// $Id: sina_login.info,v 0.1 20110523 Felix $

function open_weibo_admin_settings(){
	global $base_url;
  $form['open_weibo_enabled'] = array(
    '#type' => 'radios',
    '#title' => '启用新浪微博登录本站',
    '#default_value' => variable_get('open_weibo_enabled', 1),
    '#options' => array(t("禁用"), t('启用')),
    '#required' => TRUE,
  );
  $form['open_weibo_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('新浪微博APP_KEY'),
    '#default_value' => variable_get('open_weibo_app_key', '213710***1'),
    '#description' => 'http://api.weibo.com',
    '#required' => TRUE,
  );
  $form['open_weibo_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('新浪微博APP_SECRET'),
    '#default_value' => variable_get('open_weibo_app_secret', '25d717c8bddc*****bc374f33f2ca84b'),
    '#required' => TRUE,
  );
  $form['open_weibo_redirect_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('App回调地址redirect_uri'),
    '#default_value' => $base_url.'?q=open/weibo',
    '#required' => TRUE,
  );
	//optional
  /*$form['open_weibo_auto_post'] = array(
    '#type' => 'select',
    '#title' => t('自动发送微博？'),
    '#options' => array('0' => '否', '1' => '是'),
    '#default_value' => variable_get('open_weibo_auto_post', '0'),
    '#description' => '登录时是否自动发送微博',
    '#required' => FALSE,
  );
  $form['open_weibo_auto_post_text'] = array(
    '#type' => 'textarea',
    '#title' => t('自动发送微博微博内容'),
    '#default_value' => variable_get('open_weibo_auto_post_text', '@user已登录@site，赶快去看看吧！http://...'),
    '#description' => '自动发送微博的内容',
    '#required' => FALSE,
  );*/
  return system_settings_form($form);
}