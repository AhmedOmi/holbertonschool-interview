
#!/usr/bin/python3
""" Module that parse a log """
import sys


count = 0
codes_dict = {'200': 0, '301': 0, '400': 0, '401': 0,
              '403': 0, '404': 0, '405': 0, '500': 0}
file_size = 0

try:
    for line in sys.stdin:
        list_line = line.split()
        if len(list_line) > 2:
            count += 1
            code = list_line[-2]
            line_size = int(list_line[-1])
            if code in codes_dict:
                codes_dict[code] += 1
            file_size += line_size
        if count % 10 == 0:
            print('File size: {}'.format(file_size))
            for k, v in sorted(codes_dict.items()):
                if v > 0:
                    print('{}: {}'.format(k, v))
finally:
    print('File size: {}'.format(file_size))
    for k, v in sorted(codes_dict.items()):
        if v > 0:
            print('{}: {}'.format(k, v))
