# Log Parsing

Exercise to practice for interviews

## Context

### 0. Log parsing

Write a script that reads `stdin` line by line and computes metrics

* Input format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`
* After every 10 lines and/or a keyboard interruption (`CTRL + C`), print these statistics from the beginning:
    * Total file size: File size: <total size>
    * where `<total size>` is the sum of all previous `<file size>` (see input format above)
    * Number of lines by status code:
        * possible status code: `200`, `301`, `400`, `401`, `403`, `404`, `405` and `500`
        * if a status code doesn’t appear, don’t print anything for this status code
        * format: `<status code>: <number>`
        * status codes should be printed in ascending order

```
$ cat 0-generator.py
#!/usr/bin/python3
import random
import sys
from time import sleep
import datetime

for i in range(10000):
    sleep(random.random())
    sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
        random.randint(1, 255), random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()

$ /0-generator.py | ./0-stats.py 
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
File size: 11320
200: 3
301: 2
400: 1
401: 2
403: 3
404: 4
405: 2
500: 3
File size: 16305
200: 3
301: 3
400: 4
401: 2
403: 5
404: 5
405: 4
500: 4
^CFile size: 17146
200: 4
301: 3
400: 4
401: 2
403: 6
404: 6
405: 4
500: 4
Traceback (most recent call last):
  File "./0-stats.py", line 15, in <module>
Traceback (most recent call last):
  File "./0-generator.py", line 8, in <module>
    for line in sys.stdin:
KeyboardInterrupt
    sleep(random.random())
KeyboardInterrupt
$
```
