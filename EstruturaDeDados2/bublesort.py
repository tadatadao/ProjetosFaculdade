# -5 -30 15 36 -12 -23 -33 -15 18 19 0 -70 -60 -18 14
def custom_sort(arr, order):
    has_swaps = True
    
    if order == 1:  # Ascending order
        while has_swaps:
            has_swaps = False
            for i in range(0, len(arr) - 1):
                print(arr)
                if arr[i] > arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
                    has_swaps = True
    elif order == -1:  # Descending order
        while has_swaps:
            has_swaps = False
            for i in range(0, len(arr) - 1):
                print(arr)
                if arr[i] < arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
                    has_swaps = True

def print_instructions():
    print('Enter 1 for ascending order')
    print('Enter -1 for descending order')

# Main program
numbers = [-5, -30, 15, 36, -12, -23, -33, -15, 18, 19, 0, -70, -60, -18, 14]
print_instructions()

order_option = int(input('Enter an option for sorting: '))
while order_option < -1 or order_option > 1 or order_option == 0:
    print_instructions()
    order_option = int(input('Enter an option for sorting: '))

custom_sort(numbers, order_option)
