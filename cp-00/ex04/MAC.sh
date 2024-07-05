#!/bin/bash
ifconfig -aL | sed -e '/ether/!d' -e 's/.*ether //' -e 's/ //'
