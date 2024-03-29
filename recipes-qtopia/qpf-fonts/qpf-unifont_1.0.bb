require qpf.inc

DESCRIPTION = "Unicode fonts - QPF Edition"
LICENSE = "GPLv2 | QPL"
RPROVIDES_${PN} = "virtual-japanese-font"
PR = "r3"

SRC_URI = "http://www.openzaurus.org/mirror/qpf-unifont.tar.bz2;subdir=${BPN}-${PV}"

SRC_URI[md5sum] = "92f6df1c5edb26351332df4f576dbb10"
SRC_URI[sha256sum] = "c1c5b5ab3431896502c9275daeb47610fb2a840faa6d580e140909a3f4ef7391"
