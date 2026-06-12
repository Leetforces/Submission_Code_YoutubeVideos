LATEST_FILE=$(ssh ${USER}@${HOST} \

"find ${REMOTE_DIR} -maxdepth 1 -type f -name '${FILE_PREFIX}*' \

-printf '%T@ %f\n' | sort -nr | head -1 | cut -d' ' -f2")

