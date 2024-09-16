def maxDistance(self, arr, n):
  d = dict()
        
  for i in range(n):
    if arr[i] not in d:
      d[arr[i]] = dict({ 'min': i, 'max': i })
    
    else:
      d[arr[i]] = dict({ 'min': d[arr[i]]['min'], 'max': i })

  a = [v['max']-v['min'] for k, v in sorted(d.items(), key=lambda item: item[1]['min']-item[1]['max'])]
  return a[0]