// YOUR CODE (wrong order):
ways = cur * c[rem][cnt] % mod * vpow[cnt] % mod;
if(nkb > k || ncarry >= maxC) continue;  // check AFTER computing ways
long ways = c[rem][cnt] * vpow[cnt] % mod;  // ways computed TWICE

// CORRECT order:
if (nkb > K || ncarry >= maxCarry) continue;  // check FIRST
long ways = C[rem][cnt] * vpow[cnt] % MOD;    // then compute once