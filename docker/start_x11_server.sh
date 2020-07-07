#!/bin/bash
docker run --gpus all \
           -p 2222:22 \
           --name madagascar-$USER \
           --env _USER=$USER \
           --env _UID=$UID \
           --env _GID="$(id -g)" \
           --env _GROUP="$(id -g -n)" \
           --env _PASSWD_HASH="$(openssl passwd -1 $USER)" \
           -v $(pwd):/nfs/rsf \
           -v /sys/fs/cgroup:/sys/fs/cgroup:ro \
           --privileged=true \
           -it madagascar-x11