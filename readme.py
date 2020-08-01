# -*- coding:utf-8 -*-
import os, json
from urllib.parse import quote
from pipe import *

def langs(problem):
    prob_exts = os.listdir(problem)
    prob_lang = []
    configs = [
        ('C',      ['c']),
        ('C++',    ['cpp', 'cc']),
        ('Go',     ['golang', 'go']),
        ('Java',   ['java']),
        ('JS',     ['javascript', 'js']),
        ('Python', ['python', 'py']),
        ('Rust',   ['rust', 'rs']),
        ('SQL',    ['sql']),
        ('Shell',  ['shell']),
    ]
    for (lang, exts) in configs:
        for ext in exts:
            if ext in prob_exts:
                prob_lang.append(lang)
                break
    return '/'.join(prob_lang)

def get_row(problem):
    basename = os.path.basename(problem)
    attr = json.load(open(os.path.join(problem, 'attr.json')))
    index = '%04d' % int(attr.get('id', '0'))
    title = '[%s]( %s )' % (attr.get('title', ''), attr.get('url', ''))
    solution = '[%s]( src/%s )' % (langs(problem), quote(basename))
    favorite = attr.get('favorite', False)
    return (index, title, solution, favorite)

def fmt_row(row):
    (index, title, solution, favorite) = row
    template = '| %s | %s | %s |'
    if favorite:
        template = '| %s | %s \u2b50 | %s |'
    return template % (index, title, solution)

if __name__ == '__main__':
    (__file__
        | Pipe(os.path.realpath)
        | Pipe(os.path.dirname)
        | Pipe(os.chdir)
    )
    ofile = open('README.md', 'w')
    ofile.write('# LeetCode Solutions\n\n')
    ofile.write('| Index | Title | Solution |\n')
    ofile.write('| :---: | :---- | :------: |\n')
    (os.listdir('src')
        | select(lambda p: os.path.join('src', p))
        | where(os.path.isdir)
        | select(get_row)
        | sort
        | select(fmt_row)
        | Pipe('\n'.join)
        | Pipe(ofile.write)
        | Pipe(lambda _: print('Done!'))
    )
