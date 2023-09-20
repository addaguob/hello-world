def create_traingle(input_message):
    rows = int(input(input_message))
    spaces = rows - 1
    for row in range(1, rows * 2, 2):
        print(' ' * spaces, '*' * row)
        spaces -= 1


def main():
    run_program = 'y'
    while run_program.lower() != 'q':
        create_traingle("Enter number of rows: ")
        run_program = input("Press 'q' to quit or other keys to continue: ")


main()
