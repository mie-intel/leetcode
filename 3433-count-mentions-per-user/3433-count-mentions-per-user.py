class Solution:
    def countMentions(self, num: int, events: List[List[str]]) -> List[int]:
        def func(a, b):
            ta = int(a[1])
            tb = int(b[1])
            if ta != tb:
                return ta - tb
            if a[0] == 'OFFLINE':
                return -1
            if b[0] == 'OFFLINE':
                return 1
            return -1
        def parseU(s):
            try:
                return int(s)
            except:
                p = s[2:]
                return int(p)
        
        s = [-1000000 for i in range(num)]
        m = [0 for i in range(num)]
        events = sorted(events, key=functools.cmp_to_key(func))
        for e in events:
            tm = int(e[1])
            # update status dulu

            if e[0] == 'OFFLINE':
                s[parseU(e[2])] = tm
            else:
                if e[2] == 'ALL':
                    for i in range(num):
                        m[i] += 1
                elif e[2] == 'HERE':
                    for i in range(num):
                        if tm - s[i] >= 60:
                            m[i] += 1
                else:
                    users = e[2].split(' ')
                    for u in users:
                        p = parseU(u)
                        m[p] += 1
        return m

