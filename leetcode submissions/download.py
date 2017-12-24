# Steps To follow to download your leetcode:
#1. Login to leetcode account on your default browser
#2. Get your session Id for leetcode.com from Browser ( for chrome: press F12, Go to Resources, Go to Cookies and copy value of field 'PHPSESSID'; you can find similar value for firefox and other browsers).
#3. Create a folder to save your leetcode codes.
#4. Keep the downloaded leetcode.py into that folder
#5. Replace PHPSESSID field in leetcode.py file with your session ID (copied in step 2)
#6. run file as 'python leetcode.py
#7. wait for all submssions to download.

# Features:
#It will download only your latest accepted submission for particular code.

import cookielib, urllib2, re, sys, HTMLParser, os.path

PHPSESSID = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6Im1hbmlrOTUxNyIsInVzZXJfc2x1ZyI6Im1hbmlrOTUxNyIsIl9hdXRoX3VzZXJfaWQiOiIyMTYzNDUiLCJSRU1PVEVfQUREUiI6IjE0LjEzOS4xNjEuMTM5IiwidGltZXN0YW1wIjoiMjAxNy0wNy0yNSAxNzozOTowOS4yNjI3NzErMDA6MDAiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJpZCI6MjE2MzQ1LCJfc2Vzc2lvbl9leHBpcnkiOjEyMDk2MDAsIl9hdXRoX3VzZXJfaGFzaCI6IjkzYWEzZDNiMGRhNTYxYzI4N2VlMmE1NTU5OTk3MmU1M2IzMjYzMzQiLCJlbWFpbCI6Im1hbmlrOTUxN0BnbWFpbC5jb20iLCJJREVOVElUWSI6ImY4NjlhMDg0MDY1NGZjYmZkZjdiYTViNWI3MGMxMWNiIn0.vF54d4YxCsdBOhyY-xUPAWHb5903MGHmBwOUocLA8tM"

def saveFileByType(code_content, parser, languages=[], postfixes=[]):
  for index, language in enumerate(languages):
    code_pattern = re.compile("""vm\.code\."""+language+""" = '.*?'""")
    matched_code = code_pattern.search(code_content)
    if(matched_code != None):
      matched_code = matched_code.group(0)
      code = matched_code.split("'")[1]
      code = code.decode('unicode_escape')
      title_pattern = re.compile("""/problems/.*</a></h4>""")
      matched_title = title_pattern.search(code_content).group(0)
      title = matched_title[matched_title.index('>')+1:matched_title.index('<')]
      filename = "".join([title, "." + postfixes[index]])
      if os.path.isfile(filename) == False:
        myFile = open(filename, 'w')
        myFile.write(code)
        myFile.close()
        print "".join(["File saved with filename: ", title, "." + postfixes[index]])
 
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
parser = HTMLParser.HTMLParser()
print parser 
opener.addheaders = [
    ('User-Agent', 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36'),
    ('Referer', 'http://oj.leetcode.com/accounts/login/'),
    ('Cookie', 'PHPSESSID=' + PHPSESSID + '; _ga=GA1.2.1193454716.1501004279; NRAGENT=tk=26e67c3be080fab2'),
    ]
 
 
for i in range(1,500):
  page = 'http://oj.leetcode.com/submissions/' + `i`
  print page
  resp = opener.open(page)
  content = resp.read()
  error_pattern = re.compile("No more submissions.")
  if error_pattern.search(content) is not None:
    print "Program finished with all your submissions have been saved"
    sys.exit()
  url_pattern = re.compile("[0-9]*/\"><strong>Accepted</strong></a>")
  for match in url_pattern.findall(content):
    url = "".join(["http://oj.leetcode.com/submissions/detail/", match.split('/')[0]])
    resp = opener.open(url)
    code_content = resp.read()
saveFileByType(code_content, parser, ["java", "python", "cpp"], ["java", "py", "cpp"])