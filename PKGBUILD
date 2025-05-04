# Maintainer: Your Name <serainox@gmail.com>
pkgname=injectty
pkgver=1.0
pkgrel=1
pkgdesc="Runtime Shell Process Injector using TIOCSTI"
arch=('x86_64')
url="https://github.com/Szmelc-INC/InjecTTY"
license=('MIT')
depends=('glibc')
makedepends=('gcc' 'git')
source=("git+$url.git#branch=main")
md5sums=('SKIP')

build() {
  cd "$srcdir/InjecTTY"
  gcc -O2 -Wall -o injectty injectty.c
}

package() {
  cd "$srcdir/InjecTTY"
  install -Dm755 injectty "$pkgdir/usr/bin/injectty"
}
