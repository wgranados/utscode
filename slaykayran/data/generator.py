from random import randint



def put_to_file(N, H, R, list, path):
    """ Puts testcase to file in secret folder.

    :param list_len: int, number of elements in list
    :param list: list of int, random list to put to file
    :param path: str, path to put it to.
    :return: None
    """
    with open(path, 'a+') as open_file:
        open_file.seek(0, 0)
        open_file.write(str(N) + ' ' + str(H) + ' ' + str(R) + '\n')
        for i in range(len(list)):
            open_file.write(str(list[i][0]) +  ' ' + str(list[i][1]) +'\n')
        open_file.write('\n')

T = 20
for t in range(4, 20):
    N = randint(2, 500)
    H = randint(2, 500)
    R = randint(2,500)-1
    arr = []
    for i in range(1, R+1):
        arr.append((i, randint(1, N)))
    put_to_file(N, H, R, arr, 'secret/{testcase}.in'.format(testcase=str(t).zfill(2)))
