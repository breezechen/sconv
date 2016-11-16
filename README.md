# sconv

A Simple codec conversion library bettwen `gb18030` and `unicode` with no dependence by using a [gbk to unicode table](http://icu-project.org/repos/icu/data/trunk/charset/source/gb18030/gbkuni30.txt).

# How to using?

```
QFile f("C:\\Users\\Administrator\\Desktop\\test.txt");
f.open(QFile::ReadOnly);

QByteArray data = f.readAll();

int size = sconv_gbk_to_unicode(data.constData(), -1, 0, 0);
qDebug() << size;
WCHAR* buf = new WCHAR[size/2];
size = sconv_gbk_to_unicode(data.constData(), -1, buf, size);
QString s = QString::fromUtf16((const char16_t *)buf, size/2);
qDebug() << s;



QFile f2("C:\\Users\\Administrator\\Desktop\\test.u.txt");
f2.open(QFile::ReadOnly);

data = f2.readAll();
int size2 = sconv_unicode_to_gbk((const WCHAR*)data.constData(), data.size()/2, 0, 0);
char* buf2 = new char[size2];
size2 = sconv_unicode_to_gbk((const WCHAR*)data.constData(), data.size()/2, buf2, size2);
```

