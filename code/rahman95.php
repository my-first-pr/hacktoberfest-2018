<?php

class HelloWorld
{
    protected $name;

    public function __construct(string $name)
    {
        $this->name = $name;
    }

    public function sayHelloWorld()
    {
        return "Hello World from {$this->name} 👋";
    }
}

$class = new HelloWorld('rahman95');
echo $class->sayHelloWorld();
