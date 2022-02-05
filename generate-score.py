from random import randint

with open('save.studentinfo', 'w') as f:
    for i in range(200):
        f.write(f'{str(i+1).zfill(3)}:{str(randint(60, 150)).zfill(3)}-'
                f'{str(randint(60, 150)).zfill(3)}-{str(randint(60, 150)).zfill(3)}'
                )
        f.write('\n')

