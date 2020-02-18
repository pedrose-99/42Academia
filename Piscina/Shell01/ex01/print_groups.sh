#!/bin/bash
groups $FT_USER | tr -s ' ' ',' | tr -d '\n'
