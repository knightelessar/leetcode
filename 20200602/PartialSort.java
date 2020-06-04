// This is Java version solution
import java.util.concurrent.ThreadLocalRandom;

class Solution {
    int[][] points;
    public int[][] kClosest(int[][] points, int K) {
        this.points = points;
        // Let's do the work(i, j, K) of partially sorting the subarray 
        // (points[i], points[i+1], ..., points[j]) 
        // so that the smallest K elements of this subarray occur 
        // in the first K positions (i, i+1, ..., i+K-1).
        sort(0, points.length - 1, K);
        return Arrays.copyOfRange(points, 0, K);
    }

    public void sort(int i, int j, int K) {
        if (i >= j) return;
        // First, we quickselect by a random pivot element from the subarray. 
        int k = ThreadLocalRandom.current().nextInt(i, j);
        // To do this in place, we have two pointers i and j, 
        // and move these pointers to the elements that are in the wrong bucket 
        // -- then, we swap these elements.
        swap(i, k);

        int mid = partition(i, j);
        int leftLength = mid - i + 1;
        // After, we have two buckets [oi, i] and [i+1, oj], 
        // where (oi, oj) are the original (i, j) values when calling work(i, j, K). 
        // Say the first bucket has 10 items and the second bucket has 15 items. 
        if (K < leftLength)
            // If we were trying to partially sort say, K = 5 items, 
            // then we only need to partially sort the first bucket: work(oi, i, 5). 
            sort(i, mid - 1, K);
        else if (K > leftLength)
            // Otherwise, if we were trying to partially sort say, K = 17 items, 
            // then the first 10 items are already partially sorted, 
            // and we only need to partially sort the next 7 items: work(i+1, oj, 7).
            sort(mid + 1, j, K - leftLength);
    }

    public int partition(int i, int j) {
        int oi = i;
        int pivot = dist(i);
        i++;

        while (true) {
            while (i < j && dist(i) < pivot)
                i++;
            while (i <= j && dist(j) > pivot)
                j--;
            if (i >= j) break;
            swap(i, j);
        }
        swap(oi, j);
        return j;
    }

    public int dist(int i) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }

    public void swap(int i, int j) {
        int t0 = points[i][0], t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }
}