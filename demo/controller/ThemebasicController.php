<?php

use smce\base\SmLib\SmController;

class ThemebasicController extends SmController
{

    public $layout='//layouts/column2';
    public $theme='basic';

    public function actionIndex()
    {
        $this->render("index");
    }

}
