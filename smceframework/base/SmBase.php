<?php

/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/smceframework
 */

namespace Smce\Base;


use Smce\Core\SmHttpException;
use Smce\Core\SmACL;

use Smce\SmAutoload;
use ActiveRecord;
use Smce;

class SmBase extends CSmBase
{
	
	
    /**
	 *
	 * void
	 *
	 * 
	 */
	
    public function run()
    {
		
		session_start();
		
        $this->router();

        if(isset(self::$config["components"]["activerecord"]) && count(self::$config["components"]["activerecord"])>0)
        {
        	$this->dbSetting();
        }

       $this->command();
    }

    /**
	 *
	 * void
	 *
	 * 
	 */

	public function commandLineRun()
    {

        $this->dbSetting();

    }

    /**
	 *
	 *
	 * @return request
	 * 
	 */

    private function getRequestUri()
    {
    	$request=str_replace($this->baseUrl(), "",isset($_SERVER["REQUEST_URI"])?$_SERVER["REQUEST_URI"]:"");

		
		if(substr($request,0,1)=="/")
		{
			$request=substr($request,1,strlen($request));
		}
			
		return str_replace("index.php", "",$request);
		
    }

     

     


      /**
     *
	 * 
	 *
	 * @void
	 * 
	 */
   
    private function router()
    {
		
		$request=$this->getRequestUri();

		$this->setControllerView($this->setSmRouter($request));
		

		define('BASE_CONTROLLER',strtolower(self::$controller));
        define('BASE_VIEW',strtolower(self::$view));
    }


      /**
     *
	 * 
	 *
	 * @void
	 * 
	 */


    private function command()
    {
        
        if(!$this->isController())
        {
        	throw new SmHttpException(404,"Controller Not Found");

        }

		$this->setLayout();


		$cController=$this->isComponentsController();


		if($cController)
		{
			$this->controllerAction($cController,"beforeAction");
		}

		$this->getControllerAction();
        
        if($cController)
		{
			$this->controllerAction($cController,"afterAction");
		}

    }

   


     


      /**
     *
	 * 
	 *
	 * @return Controller or empty;
	 * 
	 */

    private function isComponentsController()
    {
    	if (class_exists("CController")) {

			return new \CController;

		}else
		{
			return false;
		}
    }


     /**
     *
	 * 
	 *
	 * @void
	 * 
	 */

    private function setLayout()
    {

    	if(!empty(self::$controller->layout))
    	{
            $this->layout=self::$controller->layout;
    	}
    }

     /**
     *
	 * @param componentsController
	 *
	 * @void
	 * 
	 */

    public static function getControllerAction()
    {
    	$actionView = 'action'.ucfirst(self::$view);
        $actionController = ucfirst(self::$controller."Controller");
		
		
        $class = new $actionController;
		
        if (method_exists($class, $actionView)) {
           
            if (method_exists ($class , "accessRules" )) {

                $accessRules=$class->$accessRules();

                if (is_array($accessRules) && count($accessRules)>0) {

                    $SmACL=new SmACL();

                    if($SmACL->rules(
                    	$accessRules,
                    	self::$view,
                    	Smce::app()->IP,
                    	Smce::app()->getState(md5(md5("SMCE_".Smce::app()->securitycode))))
                    	){

                        $class->$actionView();
                    
                    }else{

					    throw new SmHttpException(404,"You do not have authority to allow");
					}

                }
            } else {

				$class->$actionView();

            }

        } else {

             throw new SmHttpException(404,"Page Not Found");

        }
    }
    
    /**
     *
	 * @param $class
	 * @param $action
	 *
	 * @void
	 * 
	 */
	
	public static function controllerAction($class,$action)
	{	
		if(method_exists($class, $action))
		{
			$class->$action();
		}
	}


      /**
     *
	 * @void
	 * 
	 */

    private function dbSetting()
    {
		
		SmAutoload::includeFiles();

		ActiveRecord\Config::initialize(function($cfg)
		{
			$cfg->set_model_directory(BASE_PATH."/main/model");
			
			$cfg->set_connections(SmBase::$config["components"]["activerecord"]);
		});

    }

      /**
     *
	 *
	 * @return baseUrl
	 * 
	 */

	public static function baseUrl()
	{
		return str_replace("/index.php","",$_SERVER['SCRIPT_NAME']);
	}
	

}
