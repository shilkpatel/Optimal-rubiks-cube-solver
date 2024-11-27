package solverv2;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class LimitedHash<K,V> implements Map<K,V> {
	
	private static final int MAX = 10000000;
	private Map<K, V> map;
	
	public LimitedHash()
	{
		map = new HashMap<K,V>();
	}
	
	public V put(K key, V value) {
        if (map.size() >= MAX && !map.containsKey(key)) {
             return value;
        } else {
             map.put(key, value);
             return value;
        }
    }
	public int size() 
	{
		return map.size();
	}

	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return map.isEmpty();
	}

	public boolean containsKey(Object key) {
		// TODO Auto-generated method stub
		return map.containsKey(key);
	}

	public boolean containsValue(Object value) {
		// TODO Auto-generated method stub
		return map.containsValue(value);
	}

	public V get(Object key) {
		// TODO Auto-generated method stub
		return map.get(key);
	}

	public V remove(Object key) {
		// TODO Auto-generated method stub
		return map.remove(key);
	}

	public void putAll(Map<? extends K, ? extends V> m) {
		// TODO Auto-generated method stub
		map.putAll(m);
	}

	public void clear() {
		map.clear();
		
	}

	public Set<K> keySet() {
		// TODO Auto-generated method stub
		return map.keySet();
	}

	public Collection<V> values() {
		// TODO Auto-generated method stub
		return map.values();
	}

	public Set<Entry<K, V>> entrySet() {
		// TODO Auto-generated method stub
		return map.entrySet();
	}
}
