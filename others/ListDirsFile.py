
import os
import sys

def list_dirs_file(path):
    if os.path.isfile(path):
        print os.path.basename(path)
        return
    for item in os.listdir(path):
        if (os.path.isfile(item)):
            print os.path.basename(item)
        else:
            list_dirs_file(os.path.join(path, item))
    return


if __name__ == "__main__":
    path = os.getcwd()
    if len(sys.argv) > 1:
        path = sys.argv[1]
    list_dirs_file(path)
