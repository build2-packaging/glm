./: {*/ -build/} manifest

tests/: install = false

upstream/
{
  ./: doc/ doc{*.md copying.txt}
  doc/
  {
    install.subdirs = true
    ./: doc{**}
  }
}