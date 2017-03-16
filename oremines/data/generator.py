from random import randint



def put_to_file(list_len, list, path):
    """ Puts testcase to file in secret folder.

    :param list_len: int, number of elements in list
    :param list: list of int, random list to put to file
    :param path: str, path to put it to.
    :return: None
    """
    with open(path, 'a+') as open_file:
        open_file.seek(0, 0)
        open_file.write(str(list_len) + '\n')
        for i in range(list_len):
            open_file.write(str(list[i]) + ' ')
        open_file.write('\n')

T = 20
for t in range(4, 20):
    N = randint(0, 5000)
    arr = []
    for i in range(N):
        arr.append(randint(0, 2^31-1))
    put_to_file(N, arr, 'secret/{testcase}.in'.format(testcase=str(t).zfill(2)))
