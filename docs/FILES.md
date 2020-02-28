# FILES

We can correctly state that in Unix based systems, everything is a file. There are four types of files:
* Regular file
* Device file
* Symlink
* Named pipes

## Inode vs name
In Unix, there is a separations of concerns in between the name of a file and it's characteristics descripton and id storage, the latter is called inode, and this makes possible to have different names for the same file, being different names that are linked to the same inode.

## Characteristics of an inode
An inode contains the following information
* Id of the owner of the file
* Id of the group who owns the file
* Size
* Creation date, last access date and last modified date
* Type of file
* Permissions for the user, for the group and for the rest of users
* Amount (count) of names that point to this file
* Pointers to the data blocks