import re

def fun(s):
    pattern = '([a-zA-Z0-9_\-]+)[\@]([a-zA-Z0-9]+)[\.]([a-zA-Z]{1,3})'
    match = re.search(pattern, s)

    if match:
        st, end = match.span()

        if st == 0 and end == len(s):
            return True
    
    else:
        return False

def filter_mail(emails):
    return list(filter(fun, emails))