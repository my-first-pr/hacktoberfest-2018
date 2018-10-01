#####################
# Fibonacci in Ruby #
#####################
 # main fibonacci function
def CalculateFibonacci(n)
    if (n == 0) 
        return 0
    elsif (n <= 2)
        return 1
    else
        return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2)
    end
end
 # execution with check regarding the amount of args
if(ARGV.length < 1)
    puts "argument needed. term number to iterate to, with 0 as the first term number"
else
    for arg in ARGV
        puts arg.to_s + ": " + CalculateFibonacci(arg).to_s
    end
end
