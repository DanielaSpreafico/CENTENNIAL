package org.opendaylight.yang.gen.v1.uri.onf.coremodel.corefoundationmodule.superclassesandcommonpackages.rev160305.extension;
import org.opendaylight.yangtools.yang.binding.Identifier;


public class ExtensionListKey
 implements Identifier<ExtensionList> {
    private static final long serialVersionUID = -285546145519361557L;
    private final java.lang.String _valueName;


    public ExtensionListKey(java.lang.String _valueName) {
    
    
        this._valueName = _valueName;
    }
    
    /**
     * Creates a copy from Source Object.
     *
     * @param source Source object
     */
    public ExtensionListKey(ExtensionListKey source) {
        this._valueName = source._valueName;
    }


    public java.lang.String getValueName() {
        return _valueName;
    }


    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((_valueName == null) ? 0 : _valueName.hashCode());
        return result;
    }

    @Override
    public boolean equals(java.lang.Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        ExtensionListKey other = (ExtensionListKey) obj;
        if (_valueName == null) {
            if (other._valueName != null) {
                return false;
            }
        } else if(!_valueName.equals(other._valueName)) {
            return false;
        }
        return true;
    }

    @Override
    public java.lang.String toString() {
        java.lang.StringBuilder builder = new java.lang.StringBuilder(org.opendaylight.yang.gen.v1.uri.onf.coremodel.corefoundationmodule.superclassesandcommonpackages.rev160305.extension.ExtensionListKey.class.getSimpleName()).append(" [");
        boolean first = true;
    
        if (_valueName != null) {
            if (first) {
                first = false;
            } else {
                builder.append(", ");
            }
            builder.append("_valueName=");
            builder.append(_valueName);
         }
        return builder.append(']').toString();
    }



}

