# Maintainer: Your Name <serainox@gmail.com>
pkgname=injectty
pkgver=1.0
pkgrel=1
pkgdesc="Runtime Shell Process Injector using TIOCSTI"
arch=('x86_64')
url="https://szmelc.com/"
license=('MIT')
depends=('glibc')
makedepends=('gcc')
source=("injectty.c")
md5sums=('SKIP')

build() {
  gcc -O2 -Wall -o injectty injectty.c
}

package() {
  install -Dm755 injectty "$pkgdir/usr/bin/injectty"
}
