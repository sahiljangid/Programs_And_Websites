bdaystr = input("Enter date of birth:\n")
bdaylist = bdaystr.split("/")
bday = '-'.join(bdaylist)
bdaydict = {"birthday":bday}
if 'birthday' in bdaydict:
    print(bdaydict['birthday'])