"""
Author: Damian Husted
The following code is a modified snippet of an assignment I have submitted about two weeks ago.
I am new to programming but am really enjoying it. I have almost completed my first semester of a Computer Science degree.
"""
def main():
    print("Hello World!")
    print("My name is Damian")
    text = "May your coffee be strong and your Monday be short"
    the_dict = get_word_len_dict(text)
    print_dict_in_key_order(the_dict)
    print()

    text = 'why does someone believe you when you say there are four billion stars but they have to check when you say the paint is wet'
    the_dict = get_word_len_dict(text)
    print_dict_in_key_order(the_dict)

def get_word_len_dict(text):
    word_len_dict = dict()
    for word in text.split():
        if len(word) in word_len_dict.keys():
            if word not in word_len_dict[len(word)]:
                word_len_dict[len(word)] += [word]
        else:
            word_len_dict[len(word)] = [word]
    for values in word_len_dict.values():
        values.sort()
    return word_len_dict

def print_dict_in_key_order(a_dict):
    all_keys = list(a_dict.keys())
    all_keys.sort()
    for key in all_keys:
        print(key, ":", a_dict[key])
main()
