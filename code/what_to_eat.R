# This is a random R function that outputs a random food choice (for indecisive eaters)

what_to_eat <- function(string) {
  name <- tolower(string)
  if (name == "hello") {
    writeLines("Hello World!")
  } else if (name=="meeting") { # random snack suggestions for office meetings
    meeting_snacks = c("cookies","brownies","scones","oranges","apples","banana bread","cheese","doughnuts")
    print(paste("Bring", sample(meeting_snacks,1),"to the meeting!"))
  } else if (name=="snack") { # random snack
    snacks = c("chocolate","apples","cookies","chips","cheesesteak","kimchi","burger")
    print(paste("Eat", sample(snacks,1),"!"))
  } else if (name=="cheese") { # random cheese
    cheese = c("cheddar","muenster","provolone","swiss","gouda","goat")
    print(paste("Eat", sample(cheese,1),"cheese!"))
  } else if (name=="fruit") { # fruit
    fruit = c("blueberries","apples","bananas","oranges","pineapple","watermelon","grapes")
    print(paste("Eat", sample(fruit,1),"!"))
  } else if (name=="vegetable") { # vegetables
    writeLines("Eat your veggies!")
  } else {
    writeLines("No information available/Not a valid argument. Try another argument: meeting, snack, cheese, fruit, vegetable.")
  }
}