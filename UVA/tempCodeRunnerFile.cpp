        for (int i = head[u.a[0]]; ~i; i = e[i].nex)
        {
            for (int j = head[u.a[1]]; ~j; j = e[j].nex)
            {
                for (int k = head[u.a[2]]; ~k; k = e[k].nex)
                {
                    state v;
                    v.a[0] = e[i].to;
                    v.a[1] = e[j].to;
                    v.a[2] = e[k].to;
                    v.step = u.step + 1;
                    if (!vis[v.a[0]][v.a[1]][v.a[2]] && v.a[0] != v.a[1] && v.a[1] != v.a[2] && v.a[0] != v.a[2])
                    {
                        vis[v.a[0]][v.a[1]][v.a[2]] = 1;
                        q.push(v);
                    }
                }
            }
        }