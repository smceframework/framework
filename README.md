## Hello World

![SmceFramework Hello World](http://i57.tinypic.com/28kt5xw.jpg)

## Composer
https://packagist.org/packages/smce/framework

## Features

- MVC
- PSR
- Autoload
- Session Management
- Assets Manager
- Temp Manager
- Validation
- Masterpage/Layout
- Template Engine
- GRUD
- Smce Command Line
- ORM ActiveRecord(MySQL, SQLite, PostgreSQL, Oracle)
- Using ActiveRecord on Multiple Databases
- Accses Control Lists (ACL)
- Debug
- Logger
- Router
- Use SSH to Connect to a Remote Server (SSH,FTP)
- Using multiple ssh and ftp over SSH
- Exception Class
- Zip Encoding Class
- User Agent Class
- Pagination Class
- Output Class
- MemCache Class
- Redis Class
- Migration Class
- Helper Class - Enriched With Anonymous Closure Functions
- Http Exceptions Capture (404, 403 .. vs Page)
- Widgets

# Installation

#### Ubuntu


$ cd /var/www/smceframework

$ sudo apt-get install php5-dev libpcre3-dev gcc make

$ cd build

$ ./install 

#### CentOS/RedHat/Fedora

$ cd /var/www/smceframework

$ sudo yum install php-devel pcre-devel gcc make

$ cd build

$ ./install 

#### Suse


$ cd /var/www/smceframework

$ sudo yast -i gcc make autoconf2.13 php5-devel php5-pear

$ cd build

$ ./install 

-----------

#####php.ini setting

//Suse: php.ini 'ye bu satırı ekleyin
extension=smce.so

//Centos/RedHat/Fedora: /etc/php.d/ dizine smce.ini 'ye bu satırı ekleyin
extension=smce.so

//Ubuntu/Debian: /etc/php5/conf.d/ dizine smce.ini 'ye bu satırı ekleyin.
extension=smce.so 

-----------
#####apache restart

$ service apache2 restart  


## Gelistirici Hakkinda
Samed Ceylan
