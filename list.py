

def problem_list(filename):
    result = ""
    with open(filename) as string_list:
        for line in string_list:
            if not line[0].isnumeric():
                line = line.replace('\n', '')
                result += "| " + line + " | [ ] |\n"
    return result

if __name__=="__main__":
    print(problem_list("text.txt"))