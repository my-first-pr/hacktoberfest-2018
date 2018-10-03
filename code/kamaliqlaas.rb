class HelloWorld
   def initialize(name)
      @name = name.capitalize
   end
   def say_hi
      puts "Hello #{@name}!"
   end
end

hello = HelloWorld.new("World")
hello.say_hi
