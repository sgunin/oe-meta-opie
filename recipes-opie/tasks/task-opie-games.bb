DESCRIPTION = "Tasks for OPIE stuff"
SECTION = "opie/base"
LICENSE = "MIT"
PR = "r1"

inherit task

LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58"

PACKAGES = "task-opie-games task-opie-extra-games"

RDEPENDS_task-opie-games = "opie-backgammon opie-bounce opie-buzzword opie-fifteen \
                   opie-go opie-kbill opie-kcheckers opie-kpacman opie-mindbreaker \
                   opie-minesweep opie-oyatzee opie-parashoot opie-qasteroids \
                   opie-sfcave opie-snake opie-solitaire opie-tetrix opie-tictac \
                   opie-wordgame opie-zlines opie-zsame"

#
# additional things for a >= 24mb distribution
#

RDEPENDS_task-opie-extra-games = "opie-parashoot opie-mindbreaker opie-fifteen opie-tictac \
                         opie-tetrix"

