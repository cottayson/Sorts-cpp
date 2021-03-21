#define PATH_NOT_FOUND (-1)

//информация о вершине(V) графа, используется для поиска пути
struct sIVertex {
  int  dist; // расстояние
  UINT parent; // номер предка вершины

  sIVertex(void){}
  sIVertex(int _dist, UINT _parent): dist(_dist), parent(_parent){}
};

struct sPath {
  int  dist; //вес (длина) пути
  UINT ver;  // номер вершины

  sPath(void): dist(0), ver(0u){}
  sPath(int _dist, UINT _ver): dist(_dist), ver(_ver){}
};

//функтор-компаратoр для Приоритетной очереди(PRIORITY QUEUE)
struct sCmp {
  inline bool operator () (const sPath& a, const sPath& b) const {
    return (a.dist < b.dist); //задан приоритет по возрастанию
  }
};

/* Поиск кратчайшего пути между вершиной start и вершиной end алгоритмом Дейкстры,
   оптимизированный вариант при помощи "Приоритетной очереди". Возвращает длинну пути. */
int  g_ShortestDijkstra(const xAdjMatrix* const adjmat, UINT start, UINT end, xDeque<UINT>* pdeq) {
  xPQueue<sPath, sCmp> pqs(adjmat->GetHeap());
  xBlock<sIVertex>     vinfo(adjmat->GetHeap());
  int  len;
  UINT ver;

  pdeq->Clear();
  if(! vinfo.Alloc(adjmat->GetCount(), sIVertex(INT_MAX, INT_MAX)))
    return 0;

  vinfo[start].dist = 0;
  pqs.Push( sPath(0, start) ); // добавляем в очередь начальную точку пути

  while(! pqs.IsEmpty()) { // пока очередь не пуста
    
    ver = pqs.Front().ver; // номер текущей вершины
    len = pqs.Front().dist; // оценка расстояния между текущей вершиной и вершиной start
    pqs.Pop(); // удаляем элемент sPath(номер вершины, расстояние) из очереди

    if(ver == end) 
      break; // если нашли вершину то выход из цикла
    if(len > vinfo[ver].dist) 
      continue; // если новая оценка расстояния len лучше (меньше) старой то продолжаем

    for(UINT i = 0u; i < adjmat->GetCount(); ++i) { // для всех вершин

      len = (*adjmat)[ver][i]; // получаем вес или длину пути
      if(len == INT_MAX) // игнорируем не вершину
        continue;

      if(vinfo[i].dist > (vinfo[ver].dist + len)) { // если новое расстояние меньше старого
        vinfo[i].dist   = vinfo[ver].dist + len;//делаем релаксацию
        vinfo[i].parent = ver; // запоминаем номер предыдущей вершины пути
        pqs.Push( sPath(vinfo[i].dist, i) ); // обновляем новое значение расстояния
      }
    }
  }
  // если мы вышли из цикла через break то очередь может оказаться не пустой
  // можно запомнить флаг "очередь еще не пуста" чтобы лишний раз не вызывать Clear()
  pqs.Clear(); // удаляем все элементы из очереди
  
  // если путь был найден до вершины end
  if(ver == end) {
    len  = vinfo[end].dist;
    pdeq->AddFront(end);
    while(end != start) { // выделяем путь
      pdeq->AddFront(vinfo[end].parent);
      end = vinfo[end].parent;
    }
  } else {
    // len = 0; // если путь не был найден, то считаем что его длина равна 0
    // в таком случае мы не сможем отличить ситуацию end == start, от ситуации отсутствия пути
    len = PATH_NOT_FOUND
  }

  vinfo.Clear();
  return len;
}
