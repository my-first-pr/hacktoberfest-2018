# -*- coding: utf-8 -*-

vn_greeting = u"Xin chào!"
en_greeting = "Hello!"

if __name__ == "__main__":
    try:
        print((">>> print(meaning(\"{}\") == meaning(\"{}\"))").format(
            vn_greeting, en_greeting))
    except Exception:
        print((">>> print(meaning(\"{}\") == meaning(\"{}\"))").format(
            vn_greeting.encode("utf-8"), en_greeting))

    print(True)
