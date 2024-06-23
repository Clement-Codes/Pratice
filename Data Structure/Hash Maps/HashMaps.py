hashmap = {

}

#insert
hashmap[1] = 'a'
hashmap[2] = 'b'
hashmap[3] = 'c'

#traverse
for k,v in hashmap.items():
    print(k,": ",v)

#search
if 2 in hashmap:
    del hashmap[2]

#traverse
for k,v in hashmap.items():
    print(k,": ",v) 